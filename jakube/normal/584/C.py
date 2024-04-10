def read_numbers():
    return list(map(int, input().split()))

def get_other_char(a, b):
    for c in 'abc':
        if c != a and c != b:
            return c

n, t = read_numbers()
word1 = input()
word2 = input()

# find a word, that has minimal distance to both of them
# first, number of differences
diffs = len([idx for idx, (c1, c2) in enumerate(zip(word1, word2)) if c1 != c2])
#not_diffs = [idx for idx, (c1, c2) in enumerate(zip(word1, word2)) if c1 == c2]

minimum = (diffs + 1) // 2

switches = diffs - t if t <= diffs else 0
switch_polarity = 0

if t < minimum:
    print(-1)
else:
    # create new word
    new_word = []
    for c1, c2 in zip(word1, word2):
        if c1 == c2:
            if t > diffs:
                new_word.append(get_other_char(c1, c2))
                t -= 1
            else:
                new_word.append(c1)
        else:
            if switches:
                if switch_polarity == 0:
                    new_word.append(c1)
                    switch_polarity = 1
                else:
                    new_word.append(c2)
                    switch_polarity = 0
                    switches -= 1
            else:
                new_word.append(get_other_char(c1, c2))

    print(''.join(new_word))