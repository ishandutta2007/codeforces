import os, sys, math
if os.path.exists('in.in'):
	sys.stdin = open('in.in','r')

t = int(input())
for ti in range(t):
	r,g,b = sorted(list(map(int,input().split())))
	delta = b-g
	if r < delta:
		b -= r
		ans = r + min(b,g)
	else:
		ans = delta
		r -= delta
		b -= delta
		if r&1:
			r -= 1
		t = min(r//2,b)
		ans += t*2
		r -= t*2
		b -= t
		g -= t
		ans += g

	print(ans)