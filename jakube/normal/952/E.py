n = int(input())
soft = 0
hard = 0

for i in range(n):
    x, y = input().split()
    if y == 'hard':
        hard += 1
    else:
        soft += 1

if hard < soft:
    hard, soft = soft, hard

for i in range(1, 100):
    x = i * (i // 2)
    if i % 2:
        x += (i + 1) // 2
    y = i*i - x

    # print(x, y)
    if hard <= x and soft <= y:
        print(i)
        exit(0)