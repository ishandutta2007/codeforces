def binpow(n, s):
	if s == 0:
		return 1
	if s % 2 == 0:
		b = binpow(n, s // 2)
		return b * b % 10
	else:
		return n * binpow(n, s - 1) % 10

n = int(input())
print(binpow(1378, n))