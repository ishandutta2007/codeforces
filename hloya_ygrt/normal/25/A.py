n = int(input())
inp = input().split()
odd = 0
even = 0
l1 = 0
l2 = 0
j = 1
for i in inp:
	if int(i) % 2 == 0:
		odd = j
		l1+=1
	else:
		l2+=1
		even = j
	j+=1

if l1 == 1:
	print(odd)
else:
	print(even)