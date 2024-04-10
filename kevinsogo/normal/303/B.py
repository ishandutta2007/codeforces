
def gcd(a, b):
	return a if b == 0 else gcd(b, a % b)

n, m, x, y, a, b = map(int, raw_input().strip().split())
g = gcd(a, b)
a /= g
b /= g
s = min(n / a, m / b)
a *= s
b *= s
x1 = max(0, x - (a + 1) / 2)
y1 = max(0, y - (b + 1) / 2)
x2 = x1 + a
y2 = y1 + b
if x2 > n:
	d = x2 - n
	x1 -= d
	x2 -= d
if y2 > m:
	d = y2 - m
	y1 -= d
	y2 -= d


print x1, y1, x2, y2