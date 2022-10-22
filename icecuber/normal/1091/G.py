from random import randint
from sys import *

def gcd(a,b):
    return gcd(b,a%b) if b else a

"""for i in range(10000):
    a = randint(0,2**1024)
    b = randint(0,2**1024)
    if gcd(a,b) == 234:
        print("OK")
exit(0)"""
#print(gcd(324587*34,12347858*34),file=stderr)
def factor(n):
    divisors = []
    for _ in range(60):
        x = randint(0,n-1)
        x2 = x*x%n
        print('sqrt',x2)
        stdout.flush()
        y = int(input())
        if y == -1 or y == x or -y%n == x:
            continue
        g = gcd(abs(x+y),n)
        if g != 1 and g != n:
            divisors.append(g)
            divisors.append(n//g)
        g = gcd(abs(x-y),n)
        if g != 1 and g != n:
            divisors.append(g)
            divisors.append(n//g)
    divisors = list(sorted(set(divisors)))
    #print(divisors, file=stderr)
    factors = []
    while 1:
        r = n
        for d in divisors:
            g = gcd(r,d)
            if g != 1: r = g
        if r == 1: break
        #print(r,file=stderr)
        factors.append(r)
        n //= r
    return factors

n = int(input())
l = factor(n)
print('!',len(l),*l)