for _ in range(int(input())):
    a, b = map(int, input().split())
    c, d = map(int, input().split())
    if a + b + c + d == 4:
        print(2)
    elif a + b + c + d >= 1:
        print(1)
    else:
        print(0)