n, k = map(int, raw_input().split())

a = (n - k) // 2
s = '0' * a
n -= a
while n:
	n -= 1
	a = min(a, n)
	s += '1' + '0' * a
	n -= a
print s