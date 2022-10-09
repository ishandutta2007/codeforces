n = int(input())
xd = input().split()
a = [0]
for s in xd:
	a.append(int(s))

b = [0] * (n+1)
for i in range(1, n+1):
	b[i] = b[i-1] + a[i]

sol = 0

mp = {}

def mpg(x):
	if x in mp:
		return mp[x]
	else:
		return 0

for i in range(1, n+1):
	x = a[i]
	mp[x] = mpg(x) + 1
	
	sol += i*x - b[i]
	sol -= mpg(x-1)
	sol += mpg(x+1)

print(sol)