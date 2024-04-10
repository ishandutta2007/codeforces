a=list(map(int, input().split()))
i=t=0
while sum(a) > 0:
	if a[i%3] > 0:
		a[i%3] -= min(a[i%3], 2)
	t += 1
	i += 1
print(t+29)