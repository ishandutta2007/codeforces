from sys import stdin, stdout
import sys
from fractions import gcd
from math import sqrt,log
import time
from random import randint
import random
from sets import Set
import sys
# ---------- Number Theory -------------#
def primes_upto(maxn):
    maxn+=1
    A = [False]*(maxn/2+5)
    p = 3
    while p*p<maxn:
        if not A[p>>1]:
            for j in range(p*p,maxn,2*p):
                A[(j>>1)]=True
        p+=2
    ret = [2]
    for p in range(3,maxn,2):
        if not A[(p>>1)]:
            ret.append(p)
    return ret
st = time.time()
prime_list = primes_upto(1000000)
def factor_sieve(maxn):
    maxn+=1
    factor = [0]*maxn
    lim  = int(sqrt(maxn))
    for i in range(2,lim+2):
        if factor[i] == 0:
            for j in range(i*i,maxn,i):
                factor[j] = i
    return factor
factor_list = factor_sieve(100000)
def totient_sieve(maxn): #returns an array of totient function
    factor=[]
    if maxn<100000:
        factor = factor_list
    else:
        factor = factor_sieve(maxn)
    maxn+=1
    tot = [1]*maxn
    tot[0] = 0
    for i in range(2,maxn):
        if factor[i] == 0:
            tot[i] = i-1
            continue
        x = factor[i]
        y=i/x
        if y%x == 0:
            tot[i] = tot[y]*x
        else:
            tot[i] = tot[y]*(x-1)
    return tot
def mobius_sieve(maxn):
    factor=[]
    if maxn<100000:
        factor = factor_list
    else:
        factor = factor_sieve(maxn)
    maxn+=1
    mu = [1]*maxn
    for i in range(2,maxn):
        if factor[i] == 0:
            mu[i]=-1
            continue
        x = factor[i]
        y=i/x
        if y%x == 0:
            mu[i] = 0
        else:
            mu[i]=mu[x]*mu[y]
    return mu
def _try_composite(a, d, n, s):
    if pow(a, d, n) == 1:
        return False
    for i in range(s):
        if pow(a, 2**i * d, n) == n-1:
            return False
    return True # n  is definitely composite

def is_prime(n, _precision_for_huge_n=10):
    if n < 2:
        return False
    if n in _known_primes:
        return True
    for p in _known_primes:
        if n%p==0:
            return False
    d, s = n - 1, 0
    while not d % 2:
        d, s = d >> 1, s + 1
    # Returns exact according to http://primes.utm.edu/prove/prove2_3.html
    if n < 1373653:
        return not any(_try_composite(a, d, n, s) for a in (2, 3))
    if n < 25326001:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5))
    if n < 118670087467:
        if n == 3215031751:
            return False
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7))
    if n < 2152302898747:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11))
    if n < 3474749660383:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11, 13))
    if n < 341550071728321:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11, 13, 17))
    return not any(_try_composite(a, d, n, s)
                   for a in _known_primes[:_precision_for_huge_n])

_known_primes = [2, 3]
_known_primes += [x for x in range(5, 1000, 2) if is_prime(x)]
def brent(N):#Fails for perfect squares,primes
        if N%2==0:
                return 2
        if N<100000:
            return factor_list[N]
        y,c,m = random.randint(1, N-1),random.randint(1, N-1),random.randint(1, N-1)
        g,r,q = 1,1,1
        while g==1:
                x = y
                for i in range(r):
                        y = ((y*y)%N+c)%N
                k = 0
                while (k<r and g==1):
                        ys = y
                        for i in range(min(m,r-k)):
                                y = ((y*y)%N+c)%N
                                q = q*(abs(x-y))%N
                        g = gcd(q,N)
                        k = k + m
                r = r*2
        if g==N:
                while True:
                        ys = ((ys*ys)%N+c)%N
                        g = gcd(abs(x-ys),N)
                        if g>1:
                                break

        return g
def floor_sqrt(n):
    x = max(0,int(sqrt(n))-1)
    while x*x<=n:
        x+=1
    return x-1
def prime_factors(n):# Returns all prime factors of n
    ret = Set()
    if n==1:
        return ret
    if is_prime(n):
        ret.add(n)
        return ret
    x = floor_sqrt(n)
    if x*x == n:
        return prime_factors(x)
    x = brent(n)
    n/=x
    while n%x == 0:
        n/=x
    r1 = prime_factors(x)
    r2 = prime_factors(n)
    for i in r1:
        ret.add(i)
    for i in r2:
        ret.add(i)
    return ret

n = int(stdin.readline())
a, b = [0] * n, [0] * n
g = 0
for i in range(n):
    a[i], b[i] = map(int, stdin.readline().split())
    g = gcd(g, a[i] * b[i])    

def ok(p, n):
    for j in range(n):
        if a[j] % p != 0 and b[j] % p != 0:
            return False
    return True

pf = prime_factors(g)
for p in pf:
    if ok(p, n):
        print p
        sys.exit()
print -1