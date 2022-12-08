x, y = map(int, input().split())
y -= 1
if x == 0 and y == 0:
    print("Yes")
elif x >= 1 and y >= 1:
    x -= 1
    y -= 1
    if x < y or (x - y) % 2 == 1:
        print("No")
    else:
        print("Yes")
else:
    print("No")