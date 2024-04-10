n = int(input())
r = 1
for i in range(n):
    r *= 2
    if i == 12:
        r -= 100
print(r)