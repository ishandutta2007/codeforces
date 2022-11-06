# -*- coding: utf8 -*-
q = int(input())
for i in range(q):
    n = int(input())
    amount1 = 0
    amount0 = 0
    bad = 0
    for i in range(n):
        a = input()
        if len(a) % 2 == 0:
            amount0 += 1
            if a.count('0') % 2 == 1:
                bad += 1
        else:
            amount1 += 1
    if amount1 == 0 and bad % 2 == 1:
        print(amount0 - 1)
    else:
        print(amount1 + amount0)