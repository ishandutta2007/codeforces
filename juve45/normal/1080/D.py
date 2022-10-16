def solve(n, k):

	if n >= 60:
		return "YES " + str(n - 1)

	mxxx = (4 ** n - 1) // 3
	
	if k > mxxx:
		return 'NO'

	mn, mx = 0, 0

	for i in range(n):
		mn += 2 ** (i + 1) - 1
		mx += 4 ** i
		if mn <= k and mx >= k:
			return "YES " + str(n - i - 1)
		# print(mn, mx)

	if k >= 22 and k <= 25:
		return 'YES ' + str(n - 3) # OK

	if k == 2: # OK
		if n >= 2:
			return 'YES ' + str(n - 1)
		return 'NO'
	
	if k == 3: # OK
		if n <= 2:
			return 'NO'
		return 'YES ' + str(n - 1)

	if k >= 6 and k <= 10: #OK
		return 'YES ' + str(n - 2)

t = int(input())

for i in range(t):
	n, k = map(int, input().split())
	print(solve(n, k))