def read_numbers():
    return list(map(int, input().split()))

def f(pairs):
    while pairs and pairs[0] == 0:
        pairs.pop(0)
    while pairs and pairs[-1] == 0:
        pairs.pop()

    count = 0
    parity = False
    tmp_count = 0
    for i in pairs:
        if i:
            if parity:
                tmp_count += 1
            parity = False
            tmp_count += 1
        else:
            if not parity:
                parity = True
            else:
                count += tmp_count
                tmp_count = 0
            if tmp_count == 0:
                parity = False

    count += tmp_count
    return count



if __name__ == '__main__':
    n = int(input())
    numbers = read_numbers()
    print(f(numbers))