import sys
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
t = inp[ii]; ii += 1
for _ in range(t):
	n = inp[ii]; ii += 1
	a = inp[ii:ii + n]; ii += n
	s = [0]
	for x in a:
		s.append(x + s[len(s) - 1])
	res = 0
	for x in a:
		j = 2
		for i in range(len(s)):
			if j < i + 2:
				j = i + 2
			while j < len(s) and s[j] < s[i] + x:
				j += 1
			if j < len(s) and s[j] == s[i] + x:
				res += 1
				break
	print(res)