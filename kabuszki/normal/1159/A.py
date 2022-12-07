n = input()
s = input()
for a in range(101):
    b = a
    for c in s:
        b = (b + 1 if c == '+' else b - 1)
        if b < 0:
            break
    if b >= 0:
        print(b)
        break