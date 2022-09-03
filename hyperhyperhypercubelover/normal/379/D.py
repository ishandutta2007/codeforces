def F(a, b, c, d, e, f, k):
	for _ in range(k - 2):
		a, b, c, d, e, f = d, e, f, a, b + e + (c and d), f
	return e

k, x, n, m = map(int, input().split())
for a in [True, False]:
	for c in [True, False]:
		for b in range((n - a - c) // 2 + 1):
			for d in [True, False]:
				for f in [True, False]:
					for e in range((m - d - f) // 2 + 1):
						if F(a, b, c, d, e, f, k) == x:
							print(['', 'C'][a] + 'AC' * b + 'Z' * (n - a - b - b - c) + ['', 'A'][c])
							print(['', 'C'][d] + 'AC' * e + 'Z' * (m - d - e - e - f) + ['', 'A'][f])
							exit()
print('Happy new year!')