import sys

m,n = map(int, input().split())

def ask(x):
	print(x)
	sys.stdout.flush()
	y = int(input())
	if y == 0:
		exit(0)
	return y

p = [0] * 30
for i in range(n):
	p[i] = ask(1)

l = 2
r = m
step = 0
while l <= r:
	h = (l+r) // 2
	if ask(h) * p[step % n] < 0:
		r = h-1
	else:
		l = h+1
	step += 1