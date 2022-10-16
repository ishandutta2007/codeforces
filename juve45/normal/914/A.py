n = raw_input()
a = map(int, raw_input().split())

m = set()
for i in range(1002):
	m.add(i*i)

ans = -10000000000
for x in a:
	if x not in m:
		ans = max(ans, x)

print ans