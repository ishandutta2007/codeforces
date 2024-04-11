# Bartek Kostka
#  You are not prepared!

#include "bits/stdc++.h"

n = int(input())
W = {}
for i in range(n):
    adr = input()
    adr = adr.split("/")
    if adr[-1] == '':
        adr[-1] = '?'
    domena = "/".join(adr[:3])
    adres = "/".join(adr[3:])
    #print(domena, adres)
    if domena not in W:
        W[domena] = set()
    W[domena].add(adres)

E = {}
for key, ele in W.items():
    #print(key, ele)
    lele = "#".join(sorted(list(ele)))
    if lele not in E:
        E[lele] = []
    E[lele].append(key)

res = 0
for key, ele in E.items():
    if len(ele) > 1:
        res += 1

print(res)
for key, ele in E.items():
    if len(ele) > 1:
        print(" ".join(ele))