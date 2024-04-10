p = 1000000007

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
m = int(input())

d = [1] * 300001
td = [0] * 300001
L = b[0]
for i in range(1, n):
	if a[i - 1] != 1:
		t = m % a[i - 1]
		if L < t:
			print(0)
			exit(0)
		m //= a[i - 1]
		for j in range((L - t) // a[i - 1] + 1):
			d[j] = d[j * a[i - 1] + t]
		L = (L - t) // a[i - 1]
	k = 0
	for j in range(L + b[i] + 1):
		if j <= L:
			k = (k + d[j]) % p
		td[j] = k
		if j >= b[i]:
			k = (k - d[j - b[i]] + p) % p
	L += b[i]
	for j in range(L + 1):
		d[j] = td[j]
print(d[m] if m <= L else 0)