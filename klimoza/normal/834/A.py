a, b = map(str, input().split())
n = int(input())
f1 = ["<", "v", ">", "^"]
f2 = ["^", ">", "v", "<"]
h = n * 90 % 360 // 90
r = -h
j = -h
if a == "<":
    r += 0
    j += 3
elif a == "v":
    r += 1
    j += 2
elif a == ">":
    r += 2
    j += 1
else:
    r += 3
    j += 0
if b == f1[r] == f2[j]:
    print("undefined")
elif b == f1[r]:
    print("cw")
elif b == f2[j]:
    print("ccw")
else:
    print("undefined")