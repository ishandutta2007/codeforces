from math import factorial
def C(n, k):
	return factorial(n) // (factorial(n - k) * factorial(k));
def solve(x, n):
	return C(x + n - 1, n - 1)

n = int(input())
print(solve(5, n) * solve(3, n))