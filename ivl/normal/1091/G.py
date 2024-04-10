from sys import *
from random import *

def gcd(a, b):
    while b != 0:
        a, b = b, a%b
    return a

n = int(input())

def rootaj(m):
    # while True:
    #     k = int(m**0.5)
    #     if k*k == m: return k
    #     k = k+1
    #     if k*k == m: return k
    #     m += n
    print('sqrt', m)
    stdout.flush()
    return int(input())

list = []
for i in range(99):
    m = randrange(n)
    mm = (m*m)%n
    m2 = rootaj(mm)

    p = gcd(m+m2, n)
    q = gcd(abs(m-m2), n)
    if p == 1: continue
    if q == 1: continue
    list.append(p)
    list.append(q)

primes = []

while len(list) != 0:
    a = list[-1]
    list = list[:-1]
    for p in primes:
        a = a // gcd(a, p)
    for b in list:
        g = gcd(a, b)
        if g == 1: continue
        if g == a: continue
        list.append(g)
        list.append(a//g)
        a = 1
    if a==1: continue
    primes.append(a)

print('!', len(primes), end=' ')
for p in primes:
    print(p, end=' ')

print()