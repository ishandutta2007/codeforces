# -*- coding: utf8 -*-
a = input().split()
n = int(a[0])
m = int(a[1])
d = int(a[2])
mass = list(map(int, input().split()))
d1 = {}
d1[m - 1] = n + 1 - mass[m - 1]
for i in range(m - 2, -1, -1):
    d1[i] = d1[i + 1] - mass[i]
now = 0
nowpl = 0
flag = True
while True:
    if now + d >= d1[nowpl]:
        break
    d1[nowpl] = now + d
    now = now + d + mass[nowpl] - 1
    nowpl += 1
    if nowpl >= m:
        if now + d >= n + 1:
            break
        print('NO')
        flag = False
        break    
if flag:
    print('YES')
    ret = ['0'] * n
    for i in range(m):
        for j in range(d1[i] - 1, d1[i] + mass[i] - 1):
            ret[j] = str(i + 1)
    print(' '.join(ret))