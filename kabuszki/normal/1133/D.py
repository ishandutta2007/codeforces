from fractions import gcd
from collections import Counter

n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

l = list(zip(a, b))
res = sum([1 if a[0] == 0 and a[1] == 0 else 0 for a in l])
l = list(filter(lambda a : (a[0] != 0), l))
l = [a if a[1] > 0 else (-a[0], -a[1]) for a in l]
C = Counter()
for a in l:
	d = gcd(a[0], a[1])
	b = (a[0] / d, a[1] / d)
	C[b] += 1

if len(C) > 0:
	res += C.most_common(1)[0][1]

print(res)