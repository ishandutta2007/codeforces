import sys
from fractions import gcd
from math import sqrt,log
import time
from random import randint
import random
from sets import Set
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
    if n in _known_primes or n in (0, 1):
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
def factorization(n):
    X = prime_factors(n)
    arr = []
    for i in X:
        arr.append(i)
    ret = {}
    for i in range(0,len(arr)):
        val = 0
        p = arr[i]
        while n%p == 0:
            val+=1
            n/=p
        ret[p] = val
    assert(n==1)
    return ret
def divisors(n):
    X = factorization(n)
    A=[1]
    for p in X:
        a = X[p]
        x=p**a
        z=len(A)
        B = A
        for i in range(0,z):
            val=A[i]
            mul = p
            for j in range(1,a+1):
                B.append(val*mul)
                mul*=p
        A = B
    return A
def ndiv(n):
    x = factorization(n)
    ret=1
    for i in x:
        ret*=x[i]+1
    return ret
def sorted_divisors(n):
    return sorted(divisors(n))
myp = {}
def primepi(n):#Finds pi(10**10) in 12 secs, pi(10**11) in 1 minute O(sqrt(n)) memory
    if n<=1:
        return 0
    if myp.has_key(n):
        return myp[n]
    myp.clear()
    lim=floor_sqrt(n)
    sm=[]
    la =[]
    for i in range(0,lim+1):
        sm.append(i-1)
        if i==0:
            la.append(0)
            continue
        la.append(n/i-1)
    for p in range(2,lim+1):
        if sm[p-1] == sm[p]:
            continue
        cnt_p = sm[p-1]
        q = p*p
        en = min(lim,n/q)
        for i in range(1,en+1):
            d = i*p
            if d<=lim:
                la[i]-=la[d]-cnt_p
            else:
                la[i]-=sm[n/d]-cnt_p
        for i in range(lim,q-1,-1):
            sm[i]-=sm[i/p]-cnt_p
    for i in range(1,lim+1):
        myp[i] = sm[i]
        myp[n/i] = la[i]
    return la[1]
cache={}    
def phi(n): #totient(n)
    if n in cache:
        return cache[n]
    ret = n
    x = prime_factors(n)
    for p in x:
        ret*=p-1
        ret/=p
    cache[n] = ret  
    return ret

def inv(x,a): #(x,a) = 1
    r = phi(a)-1
    ret= pow(x,r,a)
    return ret

def crt(A,B):# all elements of A are mutually coprime
    N = 1
    for i in range(0,len(A)):
        N*=A[i]
    ret = 0
    for i in range(0,len(A)):
        val = A[i]
        md = B[i]
        prod_rem = N/val
        ret+=md*(prod_rem*inv(prod_rem,val))
    ans= ret%N
    return ans
_store = {}
a1,b1,a2,b2,l,r = map(int,raw_input().split())
l = max(l,max(b1,b2))
if l > r:
    print 0
    sys.exit()
g = gcd(a1,a2)
if (b1%g + g)%g != (b2%g + g)%g:
    print 0 
    sys.exit()
X = (a1*a2)/g
A1 = a1
A2 = a2
f1,f2 = factorization(a1),factorization(a2)
for p in f1:
    if p in f2:
        if f1[p] <= f2[p]:
            A1/=(p**f1[p])
        else:
            A2/=(p**f2[p])
assert(gcd(A1,A2)==1)            
P,Q = [A1,A2],[(b1%A1 + A1)%A1, (b2%A2 + A2)%A2]
rem = crt(P,Q)
# number of numbers between l,r, which are rem modulo X
size = r-l
l = (l%X + X)%X + 10*X - rem
r = l+size
print(r/X- (l-1)/X)