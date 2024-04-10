n = int(input())
if n > 4:
	n = 4 + n % 4
print(8 ** n % 10)