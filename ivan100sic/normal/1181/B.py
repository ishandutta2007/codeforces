n = int(input())
s = input()

ar = list(sorted(range(1, n), key=lambda x: max(x, n-x)))

t = int(s)

rem = 4
for x in ar:
	if s[x] != '0':
		if rem == 0:
			break
		rem -= 1
		t = min(t, int(s[:x]) + int(s[x:]))
print(t)