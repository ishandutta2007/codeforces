n, k = map(int, input().split())
s = input()

levo = [0] * n
for i in range(1, n):
	if s[i] == '0':
		levo[i] = i
	else:
		levo[i] = levo[i-1]

l = 1
r = n-1
o = n-1

def probaj(w):
	x = 0
	jumps = 0
	while jumps < k-2:
		if x+w < n:
			y = levo[x+w]
			if y == x:
				break
			x = y
		else:
			break

		jumps += 1

	if n-1-x > w:
		return False

	return True

while l <= r:
	m = (l+r) // 2

	if probaj(m):
		o = m
		r = m-1
	else:
		l = m+1

print(o-1)