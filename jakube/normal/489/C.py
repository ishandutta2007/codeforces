def get_max_number(m, s):
    max_number = 0
    for i in range(m):
        new_digit = min(9, s)
        max_number = 10*max_number + new_digit
        s -= new_digit

    if s or len(str(max_number)) != m:
        max_number = -1

    return max_number


def get_min_number(m, s):
    if s == 0:
        return 0 if m == 1 else -1

    min_number = 0
    multiplier = 1
    for i in range(m-1):
        new_digit = min(9, s-1)
        min_number += multiplier * new_digit
        multiplier *= 10
        s -= new_digit

    if 1 <= s <= 9:
        min_number += multiplier * s
    else:
        min_number = -1

    return min_number

if __name__ == '__main__':
    m, s = map(int, input().split())
    print(' '.join(map(str, [get_min_number(m, s), get_max_number(m, s)])))