n = int(input())
s = input()
fl = False
h = 0
for i in s:
    if i == '1':
        fl = True
    else:
        h+=1
if fl:
    print("1", end = "")
print("0" * h)