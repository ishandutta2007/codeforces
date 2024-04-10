n, b = list(map(int, input().split(' ')))
X = list(map(int, input().split(' ')))
Nico = 1
x = 0
for i in range(n):
    x = x + X[n - 1 - i] * Nico
    Nico = Nico * b
n, b = list(map(int, input().split(' ')))
Y = list(map(int, input().split(' ')))
Nico = 1
y = 0
for i in range(n):
    y = y + Y[n - 1 - i] * Nico
    Nico = Nico * b
if (x < y):
    print("<")
if (x == y):
    print("=")
if (x > y):
    print(">")