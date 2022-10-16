
n = int(input())

a = list(map(int, input().split()))
cnt = 0;
m = dict()
s = 0
ans = 0

for i in a:
	m[i] = 0
	m[i - 1] = 0
	m[i + 1] = 0

for i in range(n - 1, -1, -1):
	ans += s - cnt * a[i];
	for j in range(-1, 2):
		ans -= m[a[i] + j] * ((a[i] + j) - a[i]);
	# // dbg(i, ans);
	s += a[i];
	m[a[i]] += 1;
	cnt += 1;

print(ans)

# // 9 999 999 990 000 000 000