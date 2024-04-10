x = int(input())
#x, y = map(int, input().split())

y = x//210*48

for i in range(1, x%210 + 1):
	
	if i%2 and i%3 and i%5 and i%7:
		y+=1
print(y)