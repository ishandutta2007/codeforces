import sys
from copy import copy

input = sys.stdin.readline

def find(l, ile):
    pocz = 0
    kon = len(l) - 1
    while pocz + 1 < kon:
        mid = (pocz + kon) // 2
        if l[mid] < ile:
            pocz = mid
        else:
            kon = mid
    return pocz

def solve(l, sumpref, ile, A, R, M):
    pos = find(l, ile)
    
    dol = ile * (pos + 1) - sumpref[pos]
    gora = sumpref[-1] - sumpref[pos] - ile * (len(l) - pos - 1)
    
    m = min(dol, gora)
    return min(dol * A + gora * R, (dol - m) * A + (gora - m) * R + m * M)

n, A, R, M = [int(a) for a in input().split()]
l = [int(a) for a in input().split()]
l.sort()
pocz = l[0]
kon = l[-1]
sumpref = l.copy()
for i in range(1, len(sumpref)):
    sumpref[i] += sumpref[i - 1]

while pocz + 6 < kon:
    x = (2 * pocz + kon) // 3
    y = (pocz + 2 * kon) // 3
    
    s = [solve(l, sumpref, lol, A, R, M) for lol in [pocz, x, y, kon]]
    ms = min(s)
    if s[0] == ms or s[1] == ms:
        kon = y
    else:
        pocz = x
    
print(min([solve(l, sumpref, lol, A, R, M) for lol in range(pocz, kon + 1)]))