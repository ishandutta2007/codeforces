MOD = 998244353

n, m, l, r = map(int, input().split())
if n * m % 2 == 1:
	print(pow(r - l + 1, n * m, MOD))
elif (r - l + 1) % 2 == 0:
	print(pow(r - l + 1, n * m, MOD) * (MOD + 1) // 2 % MOD)
else:
	print((pow(r - l + 1, n * m, MOD) + 1) * (MOD + 1) // 2 % MOD)