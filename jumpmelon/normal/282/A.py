n = int(input())
w = 0
for i in range(n):
    d = input()
    if d == "X++" or d == "++X":
        w = w + 1
    else:
        w = w - 1
print(w)