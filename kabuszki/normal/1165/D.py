#from fractions import gcd
from math import gcd

def jebaj():
    n = int(input())
    l = [int(a) for a in input().split()]
    l = sorted(l)
    if 1 in l:
        print(-1)
        return
    if len(set(l)) != len(l):
        print(-1)
        return
    
    x = 1
    for a in l:
        x = (a * x) // gcd(a, x)
    if x > 1000000000000:
        print(-1)
        return
    X = x
    dic = {}
    for a in l.copy():
        b = 1
        while a > 1:
            b += 1
            ile = 0
            while a % b == 0:
                a = a // b
                ile += 1
            if ile > 0:
                ile = 0
                while x % b == 0:
                    x = x // b
                    ile += 1
                if ile > 0:
                    if b not in dic.keys():
                        dic[b] = ile
                    else: 
                        dic[b] = max(dic[b], ile)
    
    if len(dic) == 1:
        b = list(dic.values())[0]
        if b == len(l):
            print(list(dic.keys())[0] ** (b + 1))
        else:
            print(-1)
        return
    
    tot = 1
    for b in dic.values():
        tot = tot * (b + 1)
    if len(l) + 2 == tot and X not in l:
        print(X)
    else:
        print(-1)

t = int(input())
for i in range(t):
    jebaj()