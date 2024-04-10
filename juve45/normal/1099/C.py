s = raw_input()
n = int(raw_input())

nr1 = s.count('?')
nr2 = s.count('*')

minl = len(s) - 2 * (nr1 + nr2)
maxl = len(s) - nr1 + nr2 * 10000;


if minl > n or maxl < n:
	print 'Impossible'
	exit(0)

l = list(s)

to_add = n - minl

ans = []

for i in range(len(l)):
	if l[i] == '?':
		if to_add > 0:
			to_add -= 1
		else: 
			ans.pop(-1)
	elif l[i] == '*':
		if to_add == 0:
			ans.pop(-1)
		else:
			to_add -= 1
			while to_add > 0:
				to_add -= 1
				ans.append(l[i - 1])
	else:
		ans.append(l[i])

print ''.join(ans)