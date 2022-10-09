x = eval(input())
print('+' * 48)
for c in str(x):
	a = int(c)
	print('+' * a)
	print('.')
	print('-' * a)