z = input()
v = map(int,raw_input().strip().split())
def norm(n):
    return 0 if n == 0 else norm(n / 10) * 2 + (1 if n % 10 else 0)

targ = {}
for w in v:
    x = norm(w)
    targ[x] = w

from itertools import *
ans = []
if 4 in targ:
    ans.append(targ[4])
if 0 in targ:
    ans.append(targ[0])
if 1 in targ or 2 in targ:
    if 1 in targ: ans.append(targ[1])
    if 2 in targ: ans.append(targ[2])
elif 3 in targ:
    ans.append(targ[3])

print len(ans)
print ' '.join(map(str,ans))