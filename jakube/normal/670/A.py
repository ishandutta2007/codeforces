n = int(input())

x = 0
if n % 7 == 6:
    x = 1
mi = (n // 7) * 2
y = min(2, n % 7)
print("{} {}".format(mi + x, mi+y))