n = int(input())
a = list(map(int, input().split()))
r = 'PRL' * a[0]
for i in range(1, n):
	r += 'R' + 'PLR' * a[i]
print(r)