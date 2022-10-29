n, m = map(int, input().split(" "))
flag2 = 0
flag1 = 0
if (n % 3 == 0):
	flag1 = 1
if (m % 3 == 0):
	flag2 = 1
s = []
f = [""] * m
for i in range(n):
	t = input()
	s.append(t)
	for j in range(m):
		f[j] += t[j]
H = [0, 0, 0]
p = []
for i in s:
	if (i == 'R' * m):
		H[0] += 1
		p.append(0)
	if (i == 'B' * m):
		H[1] += 1
		p.append(1)
	if (i == 'G' * m):
		H[2] += 1
		p.append(2)
cnt = 0
for i in range(1, len(p)):
	if (p[i] != p[i-1]):
		cnt += 1
if (H[0] == n / 3 and H[1] == n / 3 and H[2] == n / 3 and flag1 and cnt == 2):
	print("YES")
else:
	H = [0, 0, 0]
	p = []
	for i in f:
		if (i == 'R' * n):
			H[0] += 1
			p.append(0)
		if (i == 'B' * n):
			H[1] += 1
			p.append(1)
		if (i == 'G' * n):
			H[2] += 1
			p.append(2)
	cnt = 0
	for i in range(1, len(p)):
		if (p[i] != p[i-1]):
			cnt += 1
	if (H[0] == m / 3 and H[1] == m / 3 and H[2] == m / 3 and flag2 and cnt == 2):
		print("YES")
	else:
		print("NO")