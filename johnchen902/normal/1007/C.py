import random

n = int(input())

def interact(x, y):
    print(x, y, flush=True)
    return int(input())
    # a = min(100, n)
    # b = max(1, n - 100)
    # if x == a and y == b:
    #     return 0
    # avail = []
    # if x < a:
    #     avail.append(1)
    # if y < b:
    #     avail.append(2)
    # if x > a or y > b:
    #     avail.append(3)
    # return random.choice(avail)

a = [(1, 1, n + 1, n + 1)]
b = [(1, 1, n + 1, n + 1)]

while True:
    # print(a, b)
    sumarea = sum((x2 - x1) * (y2 - y1) for x1, y1, x2, y2 in a)
    assert (sumarea ==
            sum((x2 - x1) * (y2 - y1) for x1, y1, x2, y2 in b))
    target = sumarea // 3

    sumarea = 0
    for x1, y1, x2, y2 in a:
        x = x1 + (target - sumarea) // (y2 - y1)
        if x <= x2:
            break
        sumarea += (x2 - x1) * (y2 - y1)
    else:
        assert False

    sumarea = 0
    for x1, y1, x2, y2 in b:
        y = y1 + (target - sumarea) // (x2 - x1)
        if y <= y2:
            break
        sumarea += (x2 - x1) * (y2 - y1)
    else:
        assert False

    ans = interact(x, y)
    if ans == 0:
        break
    elif ans == 1:
        a = [(max(x1, x + 1), y1, x2, y2) for x1, y1, x2, y2 in a]
        b = [(max(x1, x + 1), y1, x2, y2) for x1, y1, x2, y2 in b]
    elif ans == 2:
        a = [(x1, max(y1, y + 1), x2, y2) for x1, y1, x2, y2 in a]
        b = [(x1, max(y1, y + 1), x2, y2) for x1, y1, x2, y2 in b]
    elif ans == 3:
        a = [z for x1, y1, x2, y2 in a for z in
             ((x1, y1, min(x2, x), y2),
              (max(x1, x), y1, x2, min(y, y2)))]
        b = [z for x1, y1, x2, y2 in b for z in
             ((x1, y1, x2, min(y2, y)),
              (x1, max(y1, y), min(x, x2), y2))]
    a = [(x1, y1, x2, y2) for x1, y1, x2, y2 in a
         if x1 < x2 and y1 < y2]
    b = [(x1, y1, x2, y2) for x1, y1, x2, y2 in b
         if x1 < x2 and y1 < y2]