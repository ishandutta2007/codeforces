a, b = map(int, input().split())
for _ in range(b):
    if a % 10 == 0:
        a //= 10
    else:
        a -= 1
print(a)