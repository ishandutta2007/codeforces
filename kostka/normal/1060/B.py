n = int(input())


def suma(x):
    return sum(map(int, list(str(x))))


a = 0
while a * 10 + 9 <= n:
    a = a * 10 + 9
print(suma(a) + suma(n-a))