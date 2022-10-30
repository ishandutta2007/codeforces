n = input()
a = input().split()
one = 0
two = 0
th = 0
b = []
c = []
d = []
j = 1
for i in a:
	if (i == "1"):
		one = one + 1
		b.append(j)
	if i == "2":
		two = two + 1
		d.append(j)
	if (i == "3"):
		th = th + 1
		c.append(j)
	j = j + 1
ans = min(one,min(two,th))
print(ans)
out = ""
j = 0
for i in range(int(ans)):
	print(b[j],d[j],c[j])
	j = j + 1