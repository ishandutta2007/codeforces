# Number Theory Utility functions
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
def prevprime(n):
    while not is_prime(n):
        n -= 1
    return n
def ans(n):
    if is_prime(n):
        return 1
    if is_prime(n-2) or n%2 == 0:
        return 2
    return 3        
print ans(input())