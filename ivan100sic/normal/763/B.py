print('YES')
for i in range(int(input())):
	a, b, c, d = map(int, input().split())
	print(1 + abs(a) % 2 + abs(b) % 2 * 2)