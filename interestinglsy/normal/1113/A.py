import sys

n,v = map(int,input().split())
if v >= n-1: print(n-1)
else:
	ans = v
	got = v
	for i in range(2,n):
		if got >= n-1: break
		got += 1
		ans += i
	print(ans)