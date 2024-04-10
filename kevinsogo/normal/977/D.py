def key(v):
    r = 0
    while v % 3 == 0:
        v //= 3
        r -= 1
    while v % 2 == 0:
        v //= 2
        r += 1
    return r
input()
print(*sorted(map(int, input().split()), key=key))