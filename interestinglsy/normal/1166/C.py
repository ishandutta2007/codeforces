import sys
try: sys.stdin = open('in.in','r')
except: pass

n = int(input())
a = list(map( lambda x: abs(int(x)) , input().split() ))
a.sort()
l = 0
ans = 0
for r in range(n):
	while l < r and a[l]*2 < a[r]: l += 1
	ans += r-l
print(ans)