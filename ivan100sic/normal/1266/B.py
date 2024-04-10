input()
def f(s):
	s = int(s)
	return ['NO', 'YES'][s >= 14 and s % 14 in range(1, 7)]
print(*map(f, input().split()))