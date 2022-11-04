import sys
input = sys.stdin.readline

def ProGamerMove():
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	zeros = a.count(0)
	sm = sum(a)
	s1, s2 = 0, 0
	c1, c2 = 0, 0
	res = -2
	def intersect(m1, b1, m2, b2):
		l1, r1 = m1 - b1 * k, m1 + b1 * k
		l2, r2 = m2 - b2 * k, m2 + b2 * k
		return not (r1 < l2 or r2 < l1)
	for l in range(0, n + 1):
		s2, c2 = 0, 0
		for r in range(0, n + 1):
			if l <= r:
				b1, b2, b3 = c1, c2 - c1, zeros - c2
				m1, m2, m3 = s1, s2 - s1, sm - s2
				# b1 + b3 == -b2
				# min b1, b3
				if not intersect(m1 + m3, b1 + b3, -m2, b2): continue
				r1 = max(m1 + m3 - (b1 + b3) * k, -m2 - b2 * k)
				r2 = min(m1 + m3 + (b1 + b3) * k, -m2 + b2 * k)
				res = max(res, abs(r1), abs(r2))
			if r < n:
				s2 += a[r]
				c2 += a[r] == 0
		if l < n:
			s1 += a[l]
			c1 += a[l] == 0
	print(res + 1)

n = 1
#n = int(input())
for _ in range(0, n): ProGamerMove()