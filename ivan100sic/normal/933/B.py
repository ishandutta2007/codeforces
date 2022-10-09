def solve(n, k):
	if n == 0:
		return []
	x = n%k
	return [x] + solve(-(n-x)//k, k)

n, k = map(int, input().split())
a = solve(n, k)
print(len(a))
print(*a)