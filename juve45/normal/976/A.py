n = int(input())
s = input()
if s == '0':
	print(0)
	exit(0)
n = s.count('0')
print('1' + '0' * n)