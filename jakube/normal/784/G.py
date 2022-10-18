import re

x = re.findall(r"(\d+|[+-])", input())

num = int(x[0])
nextop = True
for i in range(1, len(x)):
    if x[i] == '+':
        nextop = True
    elif x[i] == '-':
        nextop = False
    else:
        if nextop:
            num += int(x[i])
        else:
            num -= int(x[i])

s = str(num)
for d in s:
    print(ord(d)*"+" + ".>")